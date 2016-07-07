#ifndef POINTS_AND_SEGMENTS_HEADER
#define POINTS_AND_SEGMENTS_HEADER

struct segment {
  int start;
  int end;
};

struct point {
    char type;
    int value;
    int index;
};

void naivePointsAndSegments(struct segment segments[], int sCount, int points[],
    int pCount, int result[]);
void sortedPointsAndSegments(struct segment segments[], int sCount, int points[],
    int pCount, int result[]);

int orderPoints(const void* a, const void* b);
void createPoints(struct point line[], int points[], int pCount);
void createSegmentPoints(struct point line[], struct segment segments[],
                         int sCount, int pCount);

#endif
