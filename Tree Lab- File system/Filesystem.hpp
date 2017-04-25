#ifndef Filesystem_HPP
#define Filesystem_HPP

#include <iostream>
#include <vector>
#include <list>
using namespace std;

#include "StringUtil.hpp"

struct File
{
	File()
	{
		isDirectory = false;
		ptrParent = nullptr;
	}

	~File()
	{
        for ( unsigned int i = 0; i < childrenPtrs.size(); i++ )
        {
            delete childrenPtrs[i];
        }
	}

	vector<File*> childrenPtrs;
	File* ptrParent;

	bool isDirectory; // traversible
	string name;
};

class Filesystem
{
public:
    // public interfaces
    File* Find( const string& filename )
    {
        return Find( filename, m_ptrRoot );
    }

    File* GetFile( const list<string>& path, const string& filename )
    {
        return GetFile( path, filename, m_ptrRoot );
    }

private:
    // ** Implement these **
    File* Find( const string& filename, File* ptrLookAt )
    {
		File* found = nullptr;

		if (ptrLookAt->name == filename){
			return ptrLookAt;
		}
		else {			
			for each (File* child in ptrLookAt->childrenPtrs)
			{
				if (found == nullptr) {
					found = Find(filename, child);
				}
			}
		}
        return found;
    }

    File* GetFile( list<string> path, const string& filename, File* current )
    {
		if (path.size() != 0) {
			string currentFolder = path.front();
			if (currentFolder == "ROOT") {
				path.pop_front();
				return GetFile(path, filename, current);
			}
			
			for each (File* child in current->childrenPtrs)
			{
				if (child->name == currentFolder) {

					path.pop_front();
					return GetFile(path, filename, child);
				}

			}		
		}
		else {
			for each (File* child in current->childrenPtrs)
			{
				if (child->name == filename) {
					return child;
				}				
			}			
		}
		return nullptr;
    }

public:
    // Constructor / destructor
	Filesystem()
	{
		m_nodeCount = 0;
		CreateFilesystem();
	}

	~Filesystem()
	{
        delete m_ptrRoot;
	}

    // Recursive function
	string GetPath( File* ptrFile )
	{
        if ( ptrFile == nullptr )
        {
            return "";
        }

        return GetPath( ptrFile->ptrParent ) + " / " + ptrFile->name;
	}

	// Get size
	int GetSize()
	{
        return m_nodeCount;
	}

private:
    // Create data for our lab
	void CreateFilesystem()
	{
        // Create root
        m_ptrRoot = new File;
        m_ptrRoot->isDirectory = true;
        m_ptrRoot->name = "ROOT";
        m_nodeCount++;

        cout << GetPath( m_ptrRoot ) << endl;

        // Create a few files
        for ( int i = 0; i < 3; i++ )
        {
            File* newFile = new File;
            newFile->isDirectory = false;
            newFile->name = "file-" + StringUtil::ToString( i ) + ".txt";
            newFile->ptrParent = m_ptrRoot;
            m_ptrRoot->childrenPtrs.push_back( newFile );
            m_nodeCount++;

            cout << GetPath( newFile ) << endl;
        }

        // Create a few folders
        for ( int i = 0; i < 2; i++ )
        {
            File* newFile = new File;
            newFile->isDirectory = true;
            newFile->name = "folder-" + StringUtil::ToString( i );
            newFile->ptrParent = m_ptrRoot;
            m_ptrRoot->childrenPtrs.push_back( newFile );
            m_nodeCount++;

            cout << GetPath( newFile ) << endl;
        }

        // Create files and folders for subfolders
        for ( unsigned int i = 0; i < m_ptrRoot->childrenPtrs.size(); i++ )
        {
            if ( m_ptrRoot->childrenPtrs[i]->isDirectory )
            {
                // Folder
                File* newFolder = new File;
                newFolder->isDirectory = true;
                string letter = "";
                letter += char( 65 + i );
                newFolder->name = "folder-" + letter;
                newFolder->ptrParent = m_ptrRoot->childrenPtrs[i];
                m_ptrRoot->childrenPtrs[i]->childrenPtrs.push_back( newFolder );
                m_nodeCount++;

                cout << GetPath( newFolder ) << endl;

                // Files
                for ( int i = 0; i < 3; i++ )
                {
                    File* newFile = new File;
                    newFile->isDirectory = false;
                    letter = "";
                    letter += char( 65 + i );
                    newFile->name = "file-" + letter + ".txt";
                    newFile->ptrParent = m_ptrRoot->childrenPtrs[i];
                    m_ptrRoot->childrenPtrs[i]->childrenPtrs.push_back( newFile );
                    m_nodeCount++;

                    cout << GetPath( newFile ) << endl;
                }

                // Create file in this folder
                File* newFile = new File;
                newFile->isDirectory = false;
                letter = "";
                letter += char( 65 + i );
                newFile->name = "file-" + letter + ".txt";
                newFile->ptrParent = m_ptrRoot->childrenPtrs[i]->childrenPtrs[0];
                m_ptrRoot->childrenPtrs[i]->childrenPtrs[0]->childrenPtrs.push_back( newFile );
                m_nodeCount++;

                cout << GetPath( newFile ) << endl;
            }
        }

        cout << "Total nodes: " << GetSize() << endl << endl;
	}

private:
	File* m_ptrRoot;
	int m_nodeCount;
};

#endif
