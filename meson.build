project('projectPoocle', 'c')
gtkdep = dependency('gtk+-3.0')
headers = ['docList.h', 'index.h', 'wordle.h', 'patTree.h', 'fileManagement.h', 'docMath.h', 'searchEngineTasks.h', 'poocleMenu.h']
include_dir = include_directories('sources')
sources = [
  'sources/docList.c',
  'sources/index.c',
  'sources/wordle.c',
  'sources/patTree.c',
  'sources/fileManagement.c',
  'sources/docMath.c',
  'sources/searchEngineTasks.c',
  'sources/poocleMenu.c'
]
executable('poocle', sources, include_directories: include_dir, dependencies: gtkdep)