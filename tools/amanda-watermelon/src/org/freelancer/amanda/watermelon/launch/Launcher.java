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
package org.freelancer.amanda.watermelon.launch;

import com.formdev.flatlaf.intellijthemes.FlatArcDarkIJTheme;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;
import org.freelancer.amanda.watermelon.core.ApplicationContext;

/**
 * This class handles creation and launch of the editor.
 *
 * @author Javier Marrero
 */
public class Launcher
{

    private final static Object LOCK = new Object();

    public static void main(String[] args)
    {
        synchronized (LOCK)
        {
            try
            {
                // Initialize Swing
                UIManager.setLookAndFeel(new FlatArcDarkIJTheme());
                
                new ApplicationContext().start();
            }
            catch (UnsupportedLookAndFeelException ex)
            {
                Logger.getLogger(Launcher.class.getName()).
                    log(Level.SEVERE, null, ex);
            }
        }
    }
}
