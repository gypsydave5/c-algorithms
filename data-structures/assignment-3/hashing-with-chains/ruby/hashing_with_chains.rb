require "scanf"

input = scanf("%d\n%d")

mod = input[0]
count = input[1]

hash = Array.new(mod) { Array.new }

def hash_func(name, mod)
  (name.each_byte.with_index.inject(0) do |mem, (byte, index)|
    (mem + (byte * 263**index))
  end % 1000000007) % mod
end

count.times do
  command = scanf("%s %s")
  verb = command[0]

  if verb == "add"
    name = command[1]
    hash_num = hash_func name, mod
    hash[hash_num].unshift name unless hash[hash_num].include? name
  end

  if verb == "del"
    name = command[1]
    hash_num = hash_func name, mod
    hash[hash_num].delete name
  end

  if verb == "find"
    name = command[1]
    hash_num = hash_func name, mod
    if hash[hash_num].include? name
      puts 'yes'
    else
      puts 'no'
    end
  end

  if verb == "check"
    hash_num = command[1].to_i
    puts hash[hash_num].join(' ')
  end

end