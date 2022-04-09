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

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.beans.PropertyChangeEvent;
import java.beans.PropertyChangeListener;
import java.lang.ref.WeakReference;
import javax.swing.*;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import org.freelancer.amanda.watermelon.core.ApplicationContext;

/**
 *
 * @author Javier Marrero
 */
public class NewFileDialog extends JDialog
{
    
    private WeakReference<ApplicationContext> context;
    
    protected JButton cancelButton;
    protected JButton okButton;
    protected JTabbedPane topPanel;
    
    public NewFileDialog(ApplicationContext context)
    {
        super(context.getWindow(), "New File...");
        this.context = new WeakReference<>(context);

        // Set the Windows properties
        setPreferredSize(new Dimension(800, 600));

        // Initialize the graphic components
        initializeComponents();

        // Pack and initialize
        pack();
        setLocationRelativeTo(context.getWindow());
    }
    
    private void initializeComponents()
    {
        // The top panel
        topPanel = new JTabbedPane(JTabbedPane.LEFT);
        add(topPanel, BorderLayout.CENTER);
        
        JPanel generalPanel = new JPanel();
        

        // The bottom panel
        JPanel bottom = new JPanel(new FlowLayout(FlowLayout.RIGHT, 10, 10));
        add(bottom, BorderLayout.SOUTH);

        // The bottom buttons
        okButton = new JButton();
        okButton.setAction(new AbstractAction("Create")
        {
            @Override
            public void actionPerformed(ActionEvent e)
            {
            }
        });
        
        cancelButton = new JButton();
        cancelButton.setAction(new AbstractAction("Cancel")
        {
            @Override
            public void actionPerformed(ActionEvent e)
            {
                dispose();
            }
        });

        // Define the behavior and create the buttons
        JButton nextButton = new JButton(new AbstractAction("Next")
            {
                @Override
                public void actionPerformed(ActionEvent e)
                {
                    if (topPanel.getSelectedIndex() < topPanel.getTabCount() - 1)
                    {
                        topPanel.setSelectedIndex(topPanel.getSelectedIndex() +
                                                  1);
                    }
                }
            });
        
        JButton prevButton = new JButton(new AbstractAction("Previous")
            {
                @Override
                public void actionPerformed(ActionEvent e)
                {
                    topPanel.setSelectedIndex(topPanel.getSelectedIndex() - 1);
                }
            });

        // Add the bottom row
        bottom.add(nextButton);
        bottom.add(prevButton);
        bottom.add(okButton);
        bottom.add(cancelButton);
        
        // Add the change listener for the tabbed pane
        topPanel.addChangeListener((ChangeEvent e) ->
        {
            prevButton.setEnabled(true);
            nextButton.setEnabled(true);
            
            if (topPanel.getSelectedIndex() == 0)
            {
                prevButton.setEnabled(false);
            }
            if (topPanel.getSelectedIndex() == topPanel.getTabCount() - 1)
            {
                nextButton.setEnabled(false);
            }
        });
        topPanel.addTab("General", generalPanel);
    }
    
}
