#ifndef POINTS_AND_SEGMENTS_HEADER
#define POINTS_AND_SEGMENTS_HEADER

struct segment {
  int start;
  int end;
};

void naivePointsAndSegments(struct segment segments[], int sCount, int points[],
    int pCount, int result[]);

#endif
