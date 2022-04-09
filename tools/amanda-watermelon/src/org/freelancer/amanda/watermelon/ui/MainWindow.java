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
import java.awt.HeadlessException;
import java.io.IOException;
import java.lang.ref.WeakReference;
import javax.imageio.ImageIO;
import javax.swing.JComponent;
import javax.swing.JFrame;
import org.flexdock.docking.DockingConstants;
import org.flexdock.docking.DockingManager;
import org.flexdock.docking.DockingPort;
import org.flexdock.docking.defaults.DefaultDockingPort;
import org.freelancer.amanda.watermelon.core.ApplicationContext;
import org.freelancer.amanda.watermelon.core.ContentEditor;

/**
 *
 * @author Javier Marrero
 */
public class MainWindow extends JFrame
{
    
    private static JComponent registerComponent(String name,
                                                JComponent component)
    {
        DockingManager.registerDockable(component, name);
        return component;
    }
    
    private WeakReference<ApplicationContext> context;
    private DefaultDockingPort port;

    // UI components
    private ApplicationMenuBar menuBar;
    private FileExplorer fileExplorer;
    private JComponent startPanel;
    
    public MainWindow(ApplicationContext context) throws HeadlessException, IOException
    {
        super("Watermelon!");
        setDefaultCloseOperation(DISPOSE_ON_CLOSE);
        setPreferredSize(new Dimension(1024, 768));
        setExtendedState(MAXIMIZED_BOTH);
        setIconImage(ImageIO.read(getClass().getResourceAsStream("/org/freelancer/amanda/watermelon/ui/icon.png")));

        // Set fields
        this.context = new WeakReference<>(context);

        // Initialize the fields.
        menuBar = new ApplicationMenuBar(context);
        fileExplorer = new FileExplorer();
        startPanel = new StartPanel();
        
        initializeComponents();

        // Layout & set location
        add(port, BorderLayout.CENTER);
        pack();
        setLocationRelativeTo(null);
    }
    
    private void initializeComponents()
    {
        // Build & Set the menu bar
        menuBar.build();
        setJMenuBar(menuBar);

        // Create the default docking port
        port = new DefaultDockingPort();
        port.setPreferredSize(getPreferredSize());

        // Create the rest of the widgets
        fileExplorer.setDirectory(context.get().getWorkspaceManager().getCurrentDirectory());
        
        // Register any dockable
        registerComponent("Files", fileExplorer);
        registerComponent("Getting Started...", startPanel);

        // Dock the widgets
        DockingManager.dock(startPanel, (DockingPort) port,
                            DockingConstants.CENTER_REGION);
        DockingManager.dock(fileExplorer, startPanel,
                            DockingConstants.WEST_REGION, 0.15f);
        
    }
    
    public void addContentEditor(ContentEditor editor)
    {
        registerComponent(editor.getEditorName(), editor.getContainer());
        DockingManager.dock(editor.getContainer(), startPanel,
                            DockingConstants.CENTER_REGION);
    }
    
}
