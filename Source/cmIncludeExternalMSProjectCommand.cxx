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
#include "cmIncludeExternalMSProjectCommand.h"

// cmIncludeExternalMSProjectCommand
bool cmIncludeExternalMSProjectCommand::InitialPass(std::vector<std::string> const& args)
{
  if(args.size() < 2) 
  {
    this->SetError("INCLUDE_EXTERNAL_MSPROJECT called with incorrect number of arguments");
    return false;
  }

  
  if(m_Makefile->GetDefinition("WIN32")) {
    
    std::string location = args[1];
    m_Makefile->ExpandVariablesInString(location);

    std::vector<std::string> name_and_location;
    name_and_location.push_back(args[0]);
    name_and_location.push_back(location);
    
    std::vector<std::string> depends;
    if (args.size() > 2) {
      for (unsigned int i=2; i<args.size(); ++i) {
        depends.push_back(args[i]); 
      }
    }

    std::string utility_name("INCLUDE_EXTERNAL_MSPROJECT");
    utility_name += "_";
    utility_name += args[0];

    m_Makefile->AddUtilityCommand(utility_name.c_str(), "echo", "\"Include external project\"",
                                  false, name_and_location, depends);

  }
  return true;
}
