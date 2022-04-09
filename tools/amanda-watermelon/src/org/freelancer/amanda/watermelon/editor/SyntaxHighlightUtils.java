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

import java.io.File;
import org.fife.ui.rsyntaxtextarea.SyntaxConstants;

/**
 *
 * @author Javier Marrero
 */
public class SyntaxHighlightUtils implements SyntaxConstants
{
    
    public static final String SYNTAX_STYLE_AMANDA = "text/amanda";

    public static String getSyntaxHightlightLanguageForFile(File file)
    {
        String result = SYNTAX_STYLE_NONE;
        String name = file.getName();
        
        if (name.endsWith(".ama"))
        {
            result = SYNTAX_STYLE_AMANDA;
        }
        else if (name.endsWith(".c"))
        {
            result = SYNTAX_STYLE_C;
        }
        else if (name.endsWith(".cpp") || name.endsWith(".h") || name.endsWith(".hpp"))
        {
            result = SYNTAX_STYLE_CPLUSPLUS;
        }
        else if (name.endsWith(".java"))
        {
            result = SYNTAX_STYLE_JAVA;
        }
        else if (name.endsWith(".py"))
        {
            result = SYNTAX_STYLE_PYTHON;
        }
        
        return result;
    }

    private SyntaxHighlightUtils()
    {
        throw new IllegalStateException("This is an utility class.");
    }
}
