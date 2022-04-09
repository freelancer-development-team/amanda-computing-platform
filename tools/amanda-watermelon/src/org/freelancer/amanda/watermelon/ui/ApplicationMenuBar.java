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

import java.awt.event.ActionEvent;
import java.lang.ref.WeakReference;
import java.util.HashMap;
import javax.swing.*;
import org.freelancer.amanda.watermelon.core.ApplicationContext;

/**
 *
 * @author Javier Marrero
 */
public class ApplicationMenuBar extends JMenuBar
{
    
    private static ApplicationContext staticContext = null;
    
    public static Action aboutAction = new AbstractAction("About")
                     {
                         @Override
                         public void actionPerformed(ActionEvent e)
                         {
                             new AboutDialog(staticContext.getWindow()).
                                 setVisible(true);
                         }
                     };
    
    public static Action helpAction = new AbstractAction("Help")
                     {
                         @Override
                         public void actionPerformed(ActionEvent e)
                         {
                         }
                     };
    
    public static Action newFileAction = new AbstractAction("New File")
                     {
                         @Override
                         public void actionPerformed(ActionEvent e)
                         {
                             new NewFileDialog(staticContext).setVisible(true);
                         }
                     };
    
    public static Action openFileAction = new AbstractAction("Open File")
                     {
                         @Override
                         public void actionPerformed(ActionEvent e)
                         {
                             staticContext.performQueryForOpenDocument();
                         }
                     };
    
    public static Action preferencesAction = new AbstractAction("Preferences")
                     {
                         @Override
                         public void actionPerformed(ActionEvent e)
                         {
                             new PreferencesDialog(staticContext).setVisible(
                                 true);
                         }
                     };
    
    public static Action quitAction = new AbstractAction("Quit")
                     {
                         @Override
                         public void actionPerformed(ActionEvent e)
                         {
                             staticContext.quit();
                         }
                     };
    
    private static void addSeparator(JMenu menu)
    {
        menu.addSeparator();
    }
    
    private WeakReference<ApplicationContext> context;
    private HashMap<String, JMenu> menus;
    
    public ApplicationMenuBar(ApplicationContext context)
    {
        this.context = new WeakReference<>(context);
        this.menus = new HashMap<>(10);
        
        staticContext = context;
    }
    
    private void buildActions()
    {
        // File
        newFileAction.putValue(Action.ACCELERATOR_KEY, KeyStroke.getKeyStroke(
                               "control N"));
        openFileAction.putValue(Action.ACCELERATOR_KEY, KeyStroke.getKeyStroke(
                                "control O"));
        quitAction.putValue(Action.ACCELERATOR_KEY, KeyStroke.getKeyStroke(
                            "alt F4"));
    }
    
    @Override
    public JMenu add(JMenu menu)
    {
        menus.put(menu.getName(), menu);
        return super.add(menu);
    }
    
    public void build()
    {
        buildActions();
        
        JMenu fileMenu = new JMenu("File");
        JMenu editMenu = new JMenu("Edit");
        JMenu helpMenu = new JMenu("Help");

        // File
        fileMenu.add(newFileAction);
        fileMenu.add(openFileAction);
        fileMenu.addSeparator();
        
        fileMenu.addSeparator();
        fileMenu.add(preferencesAction);
        fileMenu.addSeparator();
        fileMenu.add(quitAction);

        // Help
        helpMenu.add(helpAction);
        helpMenu.addSeparator();
        helpMenu.add(aboutAction);

        // Add
        add(fileMenu);
        add(editMenu);
        add(helpMenu);
    }
    
    public JMenu find(String name)
    {
        return menus.get(name);
    }
    
}
