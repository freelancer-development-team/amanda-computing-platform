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

import java.beans.PropertyChangeSupport;
import java.io.File;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Javier Marrero
 */
public class WorkspaceManager
{
    
    public static final String PROP_CURRENTDIRECTORY = "currentDirectory";
    
    public static File getLastParentDirectory(File file)
    {
        File result = file;
        while (!result.isDirectory())
        {
            result = file.getParentFile();
        }
        return file;
    }
    
    public static List<File> listFilesForFolder(final File folder)
    {
        List<File> result = new ArrayList<>(5);
        for (final File entry : folder.listFiles())
        {
            if (entry.isDirectory())
            {
                result.addAll(listFilesForFolder(entry));
            }
            else
            {
                result.add(entry);
            }
        }
        return result;
    }
    
    private File currentDirectory;
    private final transient PropertyChangeSupport propertyChangeSupport =
                                                  new java.beans.PropertyChangeSupport(
                                                      this);
    
    public WorkspaceManager(File currentDirectory)
    {
        // Handle the case of the NULL directory.
        if (currentDirectory != null)
        {
            this.currentDirectory = currentDirectory;
        }
        else
        {
            this.currentDirectory = new File(System.getProperty(
            "user.dir"));
        }

        // Get the directory holding the file instead.
        if (!this.currentDirectory.isDirectory())
        {
            this.currentDirectory =
            getLastParentDirectory(this.currentDirectory);
        }
    }

    /**
     * @return the currentDirectory
     */
    public File getCurrentDirectory()
    {
        return currentDirectory;
    }

    /**
     * @param currentDirectory the currentDirectory to set
     */
    public void setCurrentDirectory(File currentDirectory)
    {
        // Fire a property change.
        propertyChangeSupport.firePropertyChange(PROP_CURRENTDIRECTORY,
                                                 this.currentDirectory,
                                                 currentDirectory);
        
        this.currentDirectory = currentDirectory;
    }
    
}
