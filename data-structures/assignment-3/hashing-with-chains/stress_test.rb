while true

  count = (rand 10) + 1
  mod = ((count/5)..count).to_a.sample

  o = [('a'..'z'), ('A'..'Z')].map { |i| i.to_a }.flatten

  verbs = ['add', 'del', 'check', 'find']
  words = (1..100).map {|i| (0...15).map { o[rand(o.length)] }.join}

  instructions = ""
  instructions += "#{mod}\n"
  instructions += "#{count}\n"

  count.times do
    verb = verbs.sample
    command = "#{verb} "
    if verb == "check"
      command += "#{(0...mod).to_a.sample}"
    else
      command += "#{words.sample}"
    end
    instructions += "#{command}\n"
  end

  c_output = `echo "#{instructions}" | ./c_lang/hash.bin`
  ruby_output = `echo "#{instructions}" | ruby ./ruby/hashing_with_chains.rb`

  if c_output != ruby_output
    puts "ERRROR!!!"
    puts "instructions\n=========="
    puts instructions
    puts "c output\n------------"
    puts c_output
    puts "ruby output\n------------"
    puts ruby_output
    break
  else
    print "OK! "
  end
end