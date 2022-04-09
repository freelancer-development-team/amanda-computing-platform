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
package org.freelancer.amanda.watermelon.core;

import java.awt.EventQueue;
import java.awt.HeadlessException;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JFileChooser;
import javax.swing.JOptionPane;
import javax.swing.text.Document;
import org.freelancer.amanda.watermelon.editor.SyntaxHighlightUtils;
import org.freelancer.amanda.watermelon.ui.DefaultTextEditor;
import org.freelancer.amanda.watermelon.ui.MainWindow;

/**
 * The application context handles everything related to the application state.
 * It delegates functionality on several objects that constitute the base of
 * the bussiness logic.
 *
 * @author Javier Marrero
 */
public class ApplicationContext
{

    private MainWindow window;
    private HashMap<String, Document> documents;
    private WorkspaceManager workspaceManager;

    public ApplicationContext()
    {
        try
        {            
            ///TODO: Need to complete this
            workspaceManager = new WorkspaceManager(null);
            
            documents = new HashMap<>(5);
            window = new MainWindow(this);
        }
        catch (HeadlessException | IOException ex)
        {
            Logger.getLogger(ApplicationContext.class.getName()).
                log(Level.SEVERE, null, ex);
        }
    }

    public void start()
    {

        // Set the window as visible.
        EventQueue.invokeLater(() ->
        {
            window.setVisible(true);
        });
    }

    /**
     * @return the window
     */
    public MainWindow getWindow()
    {
        return window;
    }

    public void performQueryForOpenDocument()
    {
        JFileChooser chooser = new JFileChooser();
        chooser.setMultiSelectionEnabled(true);
        chooser.setDialogTitle("Open file...");
        chooser.setFileSelectionMode(JFileChooser.FILES_ONLY);

        int option = chooser.showOpenDialog(window);
        if (option == JFileChooser.APPROVE_OPTION)
        {
            File[] selectedFiles = chooser.getSelectedFiles();

            for (File file : selectedFiles)
            {
                StringBuilder text = new StringBuilder(1000);

                try
                {
                    BufferedReader reader = new BufferedReader(new FileReader(
                                   file));
                    String line;
                    do
                    {
                        line = reader.readLine();

                        if (line != null)
                        {
                            text.append(line).append("\n");
                        }
                    }
                    while (line != null);
                }
                catch (IOException ex)
                {
                    Logger.getLogger(ApplicationContext.class.getName()).
                        log(Level.SEVERE, null, ex);
                    JOptionPane.showMessageDialog(window, ex,
                                                  "Could not open '" + file.
                                                      getName() + "'",
                                                  JOptionPane.ERROR_MESSAGE);
                }

                DefaultTextEditor editor = new DefaultTextEditor(this);
                editor.setSyntaxEditingStyle(SyntaxHighlightUtils.
                    getSyntaxHightlightLanguageForFile(file));
                editor.setName(file.getName());
                editor.setText(text.toString());

                window.addContentEditor(editor);
            }
        }
    }

    public void quit()
    {
        // Clean-up
        //TODO: Add code that decides whether to show this dialog.
        int option = JOptionPane.showConfirmDialog(window,
                                                   "Are you sure you want to quit?",
                                                   "Quit?",
                                                   JOptionPane.YES_NO_OPTION,
                                                   JOptionPane.QUESTION_MESSAGE);
        if (option == JOptionPane.YES_OPTION)
        {
            window.dispose();
        }
    }

    /**
     * @return the documents
     */
    public HashMap<String, Document> getDocuments()
    {
        return documents;
    }

    /**
     * @return the workspaceManager
     */
    public WorkspaceManager getWorkspaceManager()
    {
        return workspaceManager;
    }
}
