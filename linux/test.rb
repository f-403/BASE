
files = Dir.open '.'

files.each do|filename|

  next if filename == '.' or filename == '..' or filename == 'test.rb' or File.directory? filename
  filename =~ /(\d.*)-(.*-.*)/
  newname = $2
  puts filename
  puts $2
  File.rename filename, newname
end