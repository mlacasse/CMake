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
#ifndef cmAbstractFilesCommand_h
#define cmAbstractFilesCommand_h

#include "cmStandardIncludes.h"
#include "cmCommand.h"

class cmAbstractFilesCommand : public cmCommand
{
public:
  virtual cmCommand* Clone() 
    {
      return new cmAbstractFilesCommand;
    }

  /**
   * This is called when the command is first encountered in
   * the input file.
   */
  virtual bool InitialPass(std::vector<std::string> const& args);

  /**
   * The name of the command as specified in CMakeList.txt.
   */
  virtual const char* GetName() { return "ABSTRACT_FILES";}

  /**
   * Succinct documentation.
   */
  virtual const char* GetTerseDocumentation() 
    {
    return "A list of abstract classes, useful for wrappers.";
    }
  
  /**
   * Longer documentation.
   */
  virtual const char* GetFullDocumentation()
    {
      return
        "ABSTRACT_FILES(file1 file2 ..)";
    }
  
  cmTypeMacro(cmAbstractFilesCommand, cmCommand);
};



#endif
