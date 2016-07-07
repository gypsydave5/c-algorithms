while true
  o = [('a'..'z'), ('A'..'Z')].map { |i| i.to_a }.flatten
  words = (1..10).map {|i| (0...15).map { o[rand(o.length)] }.join}
  word = words.sample

  count = rand(100000) + 1
  mod = ((count/5)..count).to_a.sample

  c_output = `echo "#{word} #{mod}" | ./c_lang/hash-function.bin`
  ruby_output = `echo "#{word} #{mod}" | ruby ./ruby/hash_function.rb`

  if c_output != ruby_output
    puts "ERRROR!!!"
    puts "word / mod: #{word} / #{mod}"
    puts "c output: #{c_output}"
    puts "ruby output: #{ruby_output}"
    break
  else
    print "OK! "
  end
end

