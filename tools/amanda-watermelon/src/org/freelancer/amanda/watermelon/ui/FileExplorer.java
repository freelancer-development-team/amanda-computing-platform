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
import java.io.File;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTree;
import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.DefaultTreeModel;
import javax.swing.tree.TreeNode;
import org.freelancer.amanda.watermelon.core.WorkspaceManager;

/**
 *
 * @author Javier Marrero
 */
public class FileExplorer extends JPanel
{
    
    private JTree tree;
    private DefaultTreeModel model;
    private File directory;
    
    public FileExplorer()
    {
        setLayout(new BorderLayout(5, 10));
        
        tree = new JTree((TreeNode) null);
        add(new JScrollPane(tree));

        ///TODO: TEMPORARY
        model = (DefaultTreeModel) tree.getModel();
    }
    
    protected void addFile(File file, DefaultMutableTreeNode root)
    {
        if (file.isDirectory())
        {
            DefaultMutableTreeNode child = new DefaultMutableTreeNode(file.getName());
            root.add(child);
            
            for (File entry : file.listFiles())
            {
                addFile(entry, child);
            }
        }
        else
        {
            DefaultMutableTreeNode child = new DefaultMutableTreeNode(file.getName());
            root.add(child);
        }
    }
    
    public void setDirectory(File directory)
    {
        File working = directory;
        if (!directory.isDirectory())
        {
            working = WorkspaceManager.getLastParentDirectory(directory);
        }

        // Display all the contents in the JTree
        DefaultMutableTreeNode root = new DefaultMutableTreeNode(working.getName());
        addFile(working, root);
        
        model.setRoot(root);
    }
    
}
