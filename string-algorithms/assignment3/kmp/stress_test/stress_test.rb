MAX_PATTERN = 1_000_00
MAX_TEXT = 1_000_00

ALPHABET = ["A", "T", "C", "G"]

def new_pattern
  (0..rand(MAX_PATTERN)).to_a.map do |c|
    ALPHABET.sample
  end.join
end

def new_text
  (0..rand(MAX_TEXT)).to_a.map do |c|
    ALPHABET.sample
  end.join
end

def stress_test
  while true do

    text = new_text
    pattern = new_pattern

    commands = [pattern, text].join("\n")

    c_output = `echo "#{commands}" | ../c/kmp`
    print "."
    ruby_output = `echo "#{commands}" | ruby ../naive_ruby/find_substring.rb`

    if ruby_output != c_output
      puts "ERRROR\n"
      puts "------"
      puts "commands"
      puts "------"
      puts commands
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