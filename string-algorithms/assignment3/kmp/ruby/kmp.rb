def prefix(string)
  prefix_array = Array.new(string.length)
  prefix_array[0] = 0
  border = 0

  (1..string.length).each do |i|
    while ((border > 0) && (string[i] != string[border]))
      border = prefix_array[border - 1];
    end

    if (string[i] == string[border])
      border = border + 1;
    else
      border = 0;
    end

    prefix_array[i] = border;
  end

  return prefix_array
end

def find_pattern(pattern, text)
  total = pattern + "$" + text

  prefix_array = prefix(total)

  matches = []

  prefix_array.each_with_index do |item, index|
    if item == pattern.length
      matches.push(index - (2 * pattern.length))
    end
  end

  return matches
end

def main
  pattern = gets.chomp
  text = gets.chomp

  results = find_pattern(pattern, text)

  puts results.join(" ")
end

main