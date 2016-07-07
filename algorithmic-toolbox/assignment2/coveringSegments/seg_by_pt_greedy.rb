require 'scanf'

def minimum_points segments
  points = []
  segments.each do |segment|
    unless points.any? {|p| segment.include? p}
      points.push(segment.last)
    end
  end
  points
end

segment_count = scanf "%d"
segments = scanf("%d %d") do |a, b|
  (a..b)
end

segments.sort! {|a, b| a.last <=> b.last}
answer = minimum_points(segments)
puts answer.length
puts answer.join ' '
