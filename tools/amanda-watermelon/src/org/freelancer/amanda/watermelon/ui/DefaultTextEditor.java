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
package org.freelancer.amanda.watermelon.ui;

import java.awt.Font;
import java.io.IOException;
import java.lang.ref.WeakReference;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JComponent;
import javax.swing.text.Document;
import org.fife.ui.rsyntaxtextarea.*;
import org.fife.ui.rtextarea.RTextScrollPane;
import org.freelancer.amanda.watermelon.core.ApplicationContext;
import org.freelancer.amanda.watermelon.core.ContentEditor;

/**
 *
 * @author Javier Marrero
 */
public class DefaultTextEditor extends RSyntaxTextArea implements ContentEditor
{

    private WeakReference<ApplicationContext> context;
    private RTextScrollPane scrollPane;

    public DefaultTextEditor(ApplicationContext context)
    {
        scrollPane = new RTextScrollPane(this);

        // Set some default properties
        setCodeFoldingEnabled(true);
        setAntiAliasingEnabled(true);

        defaultTheme();
        
        AbstractTokenMakerFactory atmf = (AbstractTokenMakerFactory) TokenMakerFactory.getDefaultInstance();
        atmf.putMapping("text/amanda", "org.freelancer.amanda.watermelon.editor.AmandaTokenMaker");
    }

    private void defaultTheme()
    {
        try
        {
            Theme theme = Theme.load(getClass().getResourceAsStream(
                  "/org/fife/ui/rsyntaxtextarea/themes/dark.xml"));
            theme.apply(this);

            // Set the default font as specified by the configuration
            // TODO: Please complete this!
            boolean hasDefaultFont = false;
            
            SyntaxScheme scheme = getSyntaxScheme();
            for (Style style : scheme.getStyles())
            {
                Font previous = style.font;
                if (previous != null)
                {
                    Font newFont = previous.deriveFont(14.0f);
                    style.font = newFont;
                }
                else
                {
                    hasDefaultFont = true;
                    break;
                }
            }
            
            if (hasDefaultFont)
            {
                setFont(getFont().deriveFont(14.0f));
            }
        }
        catch (IOException ex)
        {
            Logger.getLogger(DefaultTextEditor.class.getName()).
                log(Level.SEVERE, null, ex);
        }

        // Revalidate the component
        revalidate();
    }

    @Override
    public JComponent getContainer()
    {
        return scrollPane;
    }

    @Override
    public String getEditorName()
    {
        return getName();
    }

    @Override
    public Document getContent()
    {
        return getDocument();
    }

}
