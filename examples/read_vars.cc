#include <cstdio>
#include <cstdlib>

int main(int argc, char** argv)
{

  //Benchmark Variables B1-13
  float vertex_division = 0;
  float pareto = 0;
  float pareto_division = 0;
  float push_pop = 0;
  float reduction = 0;

  float floating_pofloat = 0;

  float data_driven = 0;
  float indirect = 0;

  float read_only = 0;
  float read_write_shared = 0;
  float local_comp = 0;

  float contention = 0;
  float barriers = 0;

  
  //Input Variables I1-4
  float vertices = 0;
  float edges = 0;
  float max_edges = 0;
  float diameter = 0;


  //Machine Variables M1-20
  float accelerator = 0;
  
  //Multicore M Variables
  float cores = 0;
  float multithreading = 0;
  float kmp_blocktime = 0;
  float kmp_place_threads1 = 0;
  float kmp_place_threads2 = 0;
  float kmp_place_threads3 = 0;
  float kmp_affinity = 0;
  float omp_nowait = 0;
  float pragma_simd = 0;
  float omp_schedule_static = 0;
  float omp_schedule_dynamic = 0;
  float omp_schedule_guided = 0;
  float omp_schedule_auto = 0;
  float omp_schedule_chunk_size = 0;
  float omp_nested = 0;
  float omp_max_active_levels = 0;
  float gomp_spincount = 0;
  
  //GPU M Variables
  float global_threads = 0;
  float local_threads = 0;

  //Input File handling
  FILE *file0 = NULL;
  const char *filename = argv[1];
  char c;
  int lines_to_check = 0;
  char name[256];
  file0 = fopen(filename,"r");
  if (!file0) {
     printf ("Error:  Unable to open input file '%s'\n",filename);
     return 1;
  }
  
  //Input csv file read here
  for(c=getc(file0); c!=EOF; c=getc(file0))
  {
    if(c=='\n')
    {
      lines_to_check++;
    }

    //if(lines_to_check>1)
    //{
      //if(enable == 1)
      //{
        int f1 = fscanf(file0, "%[^,],%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f",
                             name,
                             &vertex_division, &pareto, &pareto_division, &push_pop, &reduction, 
                             &floating_pofloat, 
                             &data_driven, &indirect, 
                             &read_only, &read_write_shared, &local_comp,
                             &contention, &barriers,
                             &vertices, &edges, &max_edges, &diameter,
                             &accelerator,
                             &cores, &multithreading, &kmp_blocktime, &kmp_place_threads1, &kmp_place_threads2, &kmp_place_threads3, &kmp_affinity,
                             &omp_nowait, &pragma_simd,
                             &omp_schedule_static, &omp_schedule_dynamic, &omp_schedule_guided, &omp_schedule_auto, &omp_schedule_chunk_size,
                             &omp_nested, &omp_max_active_levels, &gomp_spincount,
                             &global_threads, &local_threads);
 
        if(f1 != 38 && f1 != EOF)
        {
          printf("\nError: Read %d values, expected 38. Parsing failed.",f1);
          //exit (EXIT_FAILURE);
        }
        //printf("\n %f %f", vertex_division, pareto);
      //}
    //}
  }


  return 0;

}
