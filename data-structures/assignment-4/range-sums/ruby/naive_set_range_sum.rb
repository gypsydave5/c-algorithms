require 'set'

MOD = 1000000001

def set_range_sum
  set = Set.new()
  command_count = gets.chomp.to_i
  last_sum = 0

  command_count.times do
    command, first, second = gets.chomp.split(' ')
    first = (first.to_i + last_sum) % MOD
    second = (second.to_i + last_sum) % MOD

    if command == "+"
      set.add first
    end

    if command == "-"
      set.delete first
    end

    if command == "?"
      if set.member? first
        puts("Found")
      else
        puts("Not found")
      end
    end

    if command == "s"
      in_range  = set.to_a.reject {|i| i < first || i > second}
      last_sum  = in_range.reduce(0, :+)
      puts last_sum
    end
    #puts set.to_a
  end
end

set_range_sum