/*
 * Copyright (C) 2022 Javier Marrero
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
package org.freelancer.amanda.watermelon.editor;

import javax.swing.text.Segment;
import org.fife.ui.rsyntaxtextarea.AbstractTokenMaker;
import org.fife.ui.rsyntaxtextarea.RSyntaxUtilities;
import org.fife.ui.rsyntaxtextarea.Token;
import org.fife.ui.rsyntaxtextarea.TokenMap;

/**
 *
 * @author Javier Marrero
 */
public class AmandaTokenMaker extends AbstractTokenMaker
{

    private static final String[] KEYWORDS =
    {
        "as",
        "class",
        "if",
        "interface",
        "new",
        "while"
    };

    @Override
    public void addToken(Segment segment, int start, int end, int tokenType,
                         int startOffset)
    {
        int finalTokenType = tokenType;
        if (tokenType == Token.IDENTIFIER)
        {
            int value = wordsToHighlight.get(segment, start, end);
            if (value != -1)
            {
                finalTokenType = value;
            }
        }

        super.addToken(segment, start, end, finalTokenType, startOffset);
    }

    @Override
    public TokenMap getWordsToHighlight()
    {
        TokenMap tokenMap = new TokenMap(25);

        // Keywords
        for (String keyword : KEYWORDS)
        {
            tokenMap.put(keyword, Token.RESERVED_WORD);
        }

        return tokenMap;
    }

    @Override
    public Token getTokenList(Segment sgmnt, int startTokenType, int startOffset)
    {
        resetTokenList();

        char[] array = sgmnt.array;
        int offset = sgmnt.offset;
        int count = sgmnt.count;
        int end = offset + count;

        int newStartOffset = startOffset - offset;

        int currentTokenStart = offset;
        int currentTokenType = startTokenType;

        for (int i = offset; i < end; i++)
        {
            char c = array[i];

            switch (currentTokenType)
            {
            case Token.NULL:
                currentTokenStart = i;

                switch (c)
                {
                case ' ':
                case '\t':
                    currentTokenType = Token.WHITESPACE;
                    break;
                case '"':
                    currentTokenType = Token.LITERAL_STRING_DOUBLE_QUOTE;
                    break;
                case '#':
                    currentTokenType = Token.COMMENT_EOL;
                    break;
                default:
                    if (RSyntaxUtilities.isDigit(c))
                    {
                        currentTokenType = Token.LITERAL_NUMBER_DECIMAL_INT;
                    }
                    else if (RSyntaxUtilities.isLetter(c) || c == '/' || c ==
                                                                         '_')
                    {
                        currentTokenType = Token.IDENTIFIER;
                    }
                    else
                    {
                        currentTokenType = Token.IDENTIFIER;
                    }
                    break;
                }
                break;
            case Token.WHITESPACE:
                switch (c)
                {
                case ' ':
                case '\t':
                    break;
                case '"':
                    addToken(sgmnt, currentTokenStart, i - 1, Token.WHITESPACE,
                             newStartOffset + currentTokenStart);
                    currentTokenStart = i;
                    currentTokenType = Token.LITERAL_STRING_DOUBLE_QUOTE;
                    break;
                case '#':
                    addToken(sgmnt, currentTokenStart, i - 1, Token.WHITESPACE,
                             newStartOffset + currentTokenStart);
                    currentTokenStart = i;
                    currentTokenType = Token.COMMENT_EOL;
                    break;
                default:
                    addToken(sgmnt, currentTokenStart, i - 1, Token.WHITESPACE,
                             newStartOffset + currentTokenStart);
                    currentTokenStart = i;

                    if (RSyntaxUtilities.isDigit(c))
                    {
                        currentTokenType = Token.LITERAL_NUMBER_DECIMAL_INT;
                    }
                    else if (RSyntaxUtilities.isLetter(c) || c == '/' || c ==
                                                                         '_')
                    {
                        currentTokenType = Token.IDENTIFIER;
                    }
                    else
                    {
                        currentTokenType = Token.IDENTIFIER;
                    }
                    break;
                }
                break;
            default:
            case Token.IDENTIFIER:
                switch (c)
                {
                case ' ':
                case '\t':
                    addToken(sgmnt, currentTokenStart, i, Token.IDENTIFIER,
                             newStartOffset + currentTokenStart);
                    currentTokenStart = i;
                    currentTokenType = Token.WHITESPACE;
                    break;
                case '"':
                    addToken(sgmnt, currentTokenStart, i, Token.IDENTIFIER,
                             newStartOffset + currentTokenStart);
                    currentTokenStart = i;
                    currentTokenType = Token.LITERAL_STRING_DOUBLE_QUOTE;
                    break;
                default:
                    if (RSyntaxUtilities.isLetterOrDigit(c) || c == '/' | c ==
                                                                          '_')
                    {
                        break;
                    }
                }
                break;
            case Token.LITERAL_NUMBER_DECIMAL_INT:
                switch (c)
                {
                case ' ':
                case '\t':
                    addToken(sgmnt, currentTokenStart, i,
                             Token.LITERAL_NUMBER_DECIMAL_INT, newStartOffset +
                                                               currentTokenStart);
                    currentTokenStart = i;
                    currentTokenType = Token.WHITESPACE;
                    break;
                case '"':
                    addToken(sgmnt, currentTokenStart, i,
                             Token.LITERAL_NUMBER_DECIMAL_INT, newStartOffset +
                                                               currentTokenStart);
                    currentTokenStart = i;
                    currentTokenType = Token.LITERAL_STRING_DOUBLE_QUOTE;
                    break;
                default:
                    if (RSyntaxUtilities.isDigit(c))
                    {
                        break;
                    }

                    addToken(sgmnt, currentTokenStart, i - 1,
                             Token.LITERAL_NUMBER_DECIMAL_INT, newStartOffset +
                                                               currentTokenStart);
                    i--;
                    currentTokenType = Token.NULL;
                }
                break;
            case Token.COMMENT_EOL:
                i = end - 1;
                addToken(sgmnt, currentTokenStart, i, currentTokenType,
                         newStartOffset + currentTokenStart);
                currentTokenStart = i;
                currentTokenType = Token.NULL;
                break;
            case Token.LITERAL_STRING_DOUBLE_QUOTE:
                if (c == '"')
                {
                    addToken(sgmnt, currentTokenStart, i, Token.LITERAL_STRING_DOUBLE_QUOTE, newStartOffset + currentTokenStart);
                    currentTokenType = Token.NULL;
                    break;
                }
                break;
            }
        }

        switch (currentTokenType)
        {
        case Token.LITERAL_STRING_DOUBLE_QUOTE:
            addToken(sgmnt, currentTokenStart, end - 1, currentTokenType,
                     newStartOffset + currentTokenStart);
            break;
        case Token.NULL:
            addNullToken();
            break;
        default:
            addToken(sgmnt, currentTokenStart, end - 1, currentTokenType,
                     newStartOffset + currentTokenStart);
            addNullToken();
        }

        return firstToken;
    }

}
