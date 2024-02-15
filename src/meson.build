app_sources = [
  'details_row.cpp',
  'details_list.cpp',
  'app_window_builder.cpp',
  'app_window.cpp',
  'application.cpp',
  'main.cpp'
]

app_deps = [
  dependency('gtkmm-4.0', required : true)
]

add_project_arguments('-DG_DISABLE_ASSERT', language : 'cpp')

executable('gtkscaffoldcpp',
  app_sources,
  dependencies: app_deps,
  install: true,
)



