/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    $RCSfile$
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

  Copyright (c) 2002 Insight Consortium. All rights reserved.
  See ITKCopyright.txt or http://www.itk.org/HTML/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even 
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR 
     PURPOSE.  See the above copyright notices for more information.

=========================================================================*/
#ifndef cmAuxSourceDirectoryCommand_h
#define cmAuxSourceDirectoryCommand_h

#include "cmStandardIncludes.h"
#include "cmCommand.h"

/** \class cmAuxSourceDirectoryCommand
 * \brief Specify auxiliary source code directories.
 *
 * cmAuxSourceDirectoryCommand specifies source code directories
 * that must be built as part of this build process. This directories
 * are not recursively processed like the SUBDIR command (cmSubdirCommand).
 * A side effect of this command is to create a subdirectory in the build
 * directory structure.
 */
class cmAuxSourceDirectoryCommand : public cmCommand
{
public:
  /**
   * This is a virtual constructor for the command.
   */
  virtual cmCommand* Clone() 
    {
    return new cmAuxSourceDirectoryCommand;
    }

  /**
   * This is called when the command is first encountered in
   * the CMakeLists.txt file.
   */
  virtual bool InitialPass(std::vector<std::string> const& args);

  /**
   * The name of the command as specified in CMakeList.txt.
   */
  virtual const char* GetName() { return "AUX_SOURCE_DIRECTORY";}
  
  /**
   * Succinct documentation.
   */
  virtual const char* GetTerseDocumentation() 
    {
    return "Add all the source files found in the specified\n"
           "directory to the build as source list NAME.";
    }
  
  /**
   * More documentation.
   */
  virtual const char* GetFullDocumentation()
    {
    return
      "AUX_SOURCE_DIRECTORY(dir srcListName)";
    }
  
  cmTypeMacro(cmAuxSourceDirectoryCommand, cmCommand);
};



#endif
