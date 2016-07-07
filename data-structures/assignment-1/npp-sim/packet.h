#pragma once

typedef struct packet {
  long long id;
  long long t_process;
  long long t_received;
  long long t_start;
  long long t_finish;
} packet;
