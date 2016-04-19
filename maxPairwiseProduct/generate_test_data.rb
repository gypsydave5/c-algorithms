size = ARGV[1] || 10000
data = []

size.times do
  data << Random.rand(20000)
end

puts size
puts data.join " "