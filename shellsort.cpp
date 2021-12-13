
static void sortSegment(T* start, T* end, int segment_idx, int cur_segment_total)
    {
        int size = end-start;
        int cur = segment_idx + cur_segment_total;
        while (cur < size)
        {
            int temp = start[cur];
            int walker = cur - cur_segment_total;
            while (walker >= 0 && temp < start[walker])
            {
                start[walker + cur_segment_total] = start[walker];
                walker = walker - cur_segment_total;
            }
            start[walker + cur_segment_total] = temp;
            cur = cur + cur_segment_total;
        }
    }

static void ShellSort(T* start, T* end, int* num_segment_list, int num_phases)
    {
        // Note: You must print out the array after sorting segments to check whether your algorithm is true.
        int i = num_phases-1;
        while (i >= 0)
        {
            int cur = num_segment_list[i];
            int segment = 0;
            while (segment < cur)
            {
                sortSegment(start, end, segment, cur);
                segment = segment + 1;
            }
            cout << cur << " segments: ";
            printArray(start, end);
            i--;
        }
    }