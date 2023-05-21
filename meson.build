project('projectPoocle', 'c')

gtkdep = dependency('gtk+-3.0')

headers = [
  'docList.h', 'index.h', 'wordle.h', 'patTree.h',
  'fileManagement.h', 'math.h', 'searchEngineTasks.h', 'poocleMenu.h'
]

include_dir = include_directories('sources')

sources = [
  'sources/docList.c',
  'sources/index.c',
  'sources/wordle.c',
  'sources/patTree.c',
  'sources/fileManagement.c',
  'sources/math.c',
  'sources/searchEngineTasks.c',
  'sources/poocleMenu.c'
]

executable('poocle', 'main.c', sources,
           include_directories: include_dir,
           dependencies: gtkdep,
           link_args: ['-lm'])