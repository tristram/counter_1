task :default do
    sh "rake -s -T"
end

desc "Run tests."
task :test => [ :build ] do
    sh "ruby test/counter_test.rb; exit 0"
end

desc "Build library."
task :build => [
    "tmp",
    "lib",
    "lib/counter.so"
]

file "tmp" do
    directory "tmp"
end

file "lib" => [ "lib64", "lib32" ] do
    hardware = %x{uname -m}.chomp
    if hardware.eql? "x86_64"
        sh "ln -s lib64 lib"
    else
        sh "ln -s lib32 lib"
    end
end

file "lib64" do
    directory "lib64"
end

file "lib32" do
    directory "lib32"
end

file "lib/counter.so" => [ "ext/counter.c" ] do |target|
    build_so( target.name, target.prerequisites )
end

def build_so( target_name, prerequisites )
    basename = File.basename( target_name, ".so" )
    rm( Dir["tmp/*"] )
    cp( prerequisites, "tmp" )
    File.open( "tmp/extconf.rb", "w" ) do |config_file|
        config_file.puts( "require 'mkmf'" )
        config_file.puts( "create_makefile('#{basename}')" )
    end
    sh "cd tmp; ruby extconf.rb"
    sh "make -C tmp"
    cp( "tmp/#{basename}.so", "lib" )
end
