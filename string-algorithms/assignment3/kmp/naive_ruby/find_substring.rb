def find_substring
  pattern = gets.chomp
  text = gets.chomp

  results = []

  (0...text.length).each do |i|
    results.push(i) if text[i..-1].start_with? pattern
  end

  return if results.empty?
  puts results.join(" ")
end

find_substring()
