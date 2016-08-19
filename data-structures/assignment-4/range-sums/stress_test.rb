INT_MAX = 1000000000
COMMAND_MAX = 10 - 1

def add
  return "+ #{random_integer}"
end

def random_integer
  rand(INT_MAX)
end

def remove
  return "- #{random_integer}"
end

def contains
  return "? #{random_integer}"
end

def range_sum
  return "s #{random_integer} #{random_integer}"
end

def random_command
  [:add, :remove, :contains, :range_sum].map {|name| method(name)}
    .sample.call()
end

def generate_commands
  Array.new(rand(COMMAND_MAX) + 1) do
    random_command
  end
end

def commands_string(commands)
  "#{commands.length.to_s + "\n" }#{commands.join("\n")+ "\n"}"
end

def stress_test
  while true do

    commands = generate_commands()
    c_output = `echo "#{commands_string(commands)}" | ./range-sums`
    print "."
    ruby_output = `echo "#{commands_string(commands)}" | ruby ./ruby/naive_set_range_sum.rb`

    if ruby_output != c_output
      puts "ERRROR\n"
      puts "------"
      puts "commands"
      puts "------"
      puts commands_string(commands)
      puts "------"
      puts "=ruby="
      puts "======"
      puts ruby_output
      puts "======"
      puts "==c==="
      puts "======"
      puts c_output
      puts "======"
      return
    end
  end
end



stress_test()
