require "scanf"

def hash_func(name, mod)
  (name.each_byte.with_index.inject(0) do |mem, (byte, index)|
    (mem + (byte * 263**index))
  end % 1000000007) % mod
end

input = scanf("%s\n%d")

word = input[0]
mod = input[1]

puts hash_func(word, mod)

