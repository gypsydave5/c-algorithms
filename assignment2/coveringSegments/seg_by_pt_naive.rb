require 'scanf'

def main
  segment_count = scanf "%d"
  segments = scanf("%d %d") do |a, b|
    (a..b)
  end

  answer = smallest_combination(segments)
  puts answer.length
  puts answer.join ' '

end

def min_max segments
  min = 0
  max = 0

  segments.each do |segment|
    min = segment.first if min == 0 || segment.first < min
    max = segment.last if segment.last > max
  end

  [min, max]
end

def smallest_combination segments
  min, max = min_max segments
  points = (min..max).to_a

  (1...points.length).step do |pick_number|
    points.combination(pick_number) do |combination|
      if combination_covers_segments?(combination, segments)
        then return combination.to_a
      end
    end
  end
end

def combination_covers_segments? combination, segments
  segments.all? do |segment|
    combination.any? do |point|
      segment.cover? point
    end
  end
end

main