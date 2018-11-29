# 375_p5

We would like to compare Quicksort, Mergesort, Radix Sort, and Pidgeonhole Sort. We would like to compare the times they take to complete, data sets in which each sort excels and why they excel in that data set. We plan to test data sets that vary in length and range, and measure performance of each sort. We would also like to investigate how stability affects the output times, as well as if stability is important to the output. 

Mergesort:
	two different versions of mergesort were implemented. mergeSort is the standard MergeSort algorithm with tripartMSort is the modified MergeSort that divides the original array into three subarrays for sorting and merging.

	mergeSort(ArrayName, 0, ArrayName.size());
	tripartMSort(ArrayName, 0, ArrayName.size());
