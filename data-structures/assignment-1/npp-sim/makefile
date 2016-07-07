test: ut-queue

ut-queue:
	gcc linked_list.spec.c queue.c -o linked_list.spec.bin && ./linked_list.spec.bin

build-submission:
	gcc submission.c -o packet_count.bin

test-sub: build-submission
	cram test.t

acs: build
	cram test.t

build:
	gcc main.c queue.c -o packet_count.bin
