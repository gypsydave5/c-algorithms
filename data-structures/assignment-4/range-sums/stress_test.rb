INT_MAX = 10
COMMAND_MAX = 10


def add
  return "+ #{random_integer}"
end

def random_integer
  rand(INT_MAX) + 1
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

def stress_test
  commands = generate_commands().join("\n")
  c_output = `echo "#{commands.length}\n#{commands}\n" | ./range-sums`
  puts c_output
end


stress_test()
