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
#ifndef cmCacheManager_h
#define cmCacheManager_h

#include "cmStandardIncludes.h"
class cmMakefile;

/** \class cmCacheManager
 * \brief Control class for cmake's cache
 *
 * Load and Save CMake cache files.
 * 
 */
class cmCacheManager
{
public:
  enum CacheEntryType{ BOOL=0, PATH, FILEPATH, STRING, INTERNAL,STATIC };
  struct CacheEntry
  {
    std::string m_Value;
    std::string m_HelpString;
    CacheEntryType m_Type;
  };
public:
  typedef  std::map<cmStdString, CacheEntry> CacheEntryMap;
  /**
   * Types for the cache entries.  These are useful as
   * hints for a cache editor program.  Path should bring
   * up a file chooser, BOOL a check box, and STRING a 
   * text entry box, FILEPATH is a full path to a file which
   * can be different than just a path input
   */
  static CacheEntryType StringToType(const char*);
  ///! Singleton pattern get instance of the cmCacheManager.
  static cmCacheManager* GetInstance();
  
  ///! Load a cache for given makefile.  Loads from ouput home.
  bool LoadCache(cmMakefile*); 
  ///! Load a cache for given makefile.  Loads from path/CMakeCache.txt.
  bool LoadCache(const char* path);
  bool LoadCache(const char* path, bool internal);
  bool LoadCache(const char* path, bool internal, 
		 std::set<std::string>& excludes,
		 std::set<std::string>& includes);

  ///! Put cache definitions into makefile
  void DefineCache(cmMakefile*); 
  
  ///! Save cache for given makefile.  Saves to ouput home CMakeCache.txt.
  bool SaveCache(cmMakefile*) ;
  ///! Save cache for given makefile.  Saves to ouput path/CMakeCache.txt
  bool SaveCache(const char* path) ;

  ///! Print the cache to a stream
  void PrintCache(std::ostream&) const;
  
  ///! Get the cache map ivar.
  const CacheEntryMap &GetCacheMap() const { return m_Cache; }

  ///! Get a cache entry object for a key
  CacheEntry *GetCacheEntry(const char *key);
  
  bool IsAdvanced(const char* key);
  
  ///! Remove an entry from the cache
  void RemoveCacheEntry(const char* key);
  
  ///! Break up a line like VAR:type="value" into var, type and value
  static bool ParseEntry(const char* entry, 
                         std::string& var,
                         std::string& value,
                         CacheEntryType& type);
  
protected:
  ///! Add an entry into the cache
  void AddCacheEntry(const char* key, const char* value, 
                     const char* helpString, CacheEntryType type);

  ///! Add a BOOL entry into the cache
  void AddCacheEntry(const char* key, bool, const char* helpString);
  
  ///! Get a value from the cache given a key
  const char* GetCacheValue(const char* key) const;

private:
  static void OutputHelpString(std::ofstream& fout, 
                               const std::string& helpString);
  static cmCacheManager* s_Instance;
  CacheEntryMap m_Cache;
  // Only cmake and cmMakefile should be able to add cache values
  // the commands should never use the cmCacheManager directly
  friend class cmMakefile; // allow access to add cache values
  friend class cmake; // allow access to add cache values
  friend class cmakewizard; // allow access to add cache values
};

#endif
