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
#include "cmMarkAsAdvancedCommand.h"

// cmMarkAsAdvancedCommand
bool cmMarkAsAdvancedCommand::InitialPass(std::vector<std::string> const& args)
{
  if(args.size() < 1 )
    {
    this->SetError("called with incorrect number of arguments");
    return false;
    }
  unsigned int i =0;
  const char* value = "1";
  bool overwrite = false;
  if(args[0] == "CLEAR" || args[0] == "FORCE")
    {
    overwrite = true;
    if(args[0] == "CLEAR")
      {
      value = "0";
      }
    i = 1;
    }
  for(; i < args.size(); ++i)
    {
    std::string variable = args[i];
    variable += "-ADVANCED";
    std::string doc = "Advanced flag for variable: ";
    doc += args[i];
    // if not CLEAR or FORCE or it is not yet defined,
    // then define variable-ADVANCED
    if(overwrite || !m_Makefile->GetDefinition(variable.c_str()))
      {
      m_Makefile->AddCacheDefinition(variable.c_str(), value,
                                     doc.c_str(),
                                     cmCacheManager::INTERNAL);      
      }
    }
  return true;
}

