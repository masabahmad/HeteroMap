#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string.h>

#include <time.h>
#include <sys/timeb.h>

#define BILLION 1E9


//Multicore Specification Defines
#define CORESMIN 2
#define MTMIN 1
#define BLOCKTIMEMIN 1
#define OFFSETMIN 1
#define KMP_AFFINITY_MIN 0
#define SIMDMIN 1

#define max_cores 61
#define max_multithreading 4
#define max_blocktime 1000
#define max_thread_placement max_cores
char affinity_type[10];
#define max_simd 16
#define MIN_OMP_CHUNK_SIZE 8
#define MAX_CHUNK_SIZE 128 //in powers of 2
#define MAX_NESTING 5
#define MIN_NESTING 0
#define MAX_SPINS 100
#define MIN_SPINS 0

//GPU Specification Defines
#define GPUMIN 32

#define max_global_threads 1048576
#define max_local_threads 1024

int main(int argc, char** argv)
{

  //Benchmark Variables B1-13
  float vertex_division = 0;
  float pareto = 0;
  float pareto_division = 0;
  float push_pop = 0;
  float reduction = 0;

  float floating_point = 0;

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
  const int rows = atoi(argv[1]);
  int line_counter = 0;
  const char *filename = argv[2];
  //char c;
  int lines_to_check = 0;
  char name[256] = {' '};
  file0 = fopen(filename,"r");
  if (!file0) {
     printf ("Error:  Unable to open input file '%s'\n",filename);
     return 1;
  }
  
  //Input csv file read here
  //for(c=getc(file0); c!=EOF; c=getc(file0))
  //{
  //  if(c=='\n')
  //  {
  //    lines_to_check++;
  //  }
  for(int i=0;i<rows;i++)
  {
        for(int j=0;j<256;j++)
        {
          name[j] = ' ';
        }
        int f1 = fscanf(file0, "%[^,],%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f",
                             name,
                             &vertex_division, &pareto, &pareto_division, &push_pop, &reduction, 
                             &floating_point, 
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
          //printf("\nError: Read %d values, expected 38. Parsing failed.",f1);
          //exit (EXIT_FAILURE);
        }
        //printf("\n %f %f", vertex_division, pareto);
      //}
    //}
    line_counter++; lines_to_check = rows; lines_to_check++; 
  //}

  printf("\n \n");
  for(int i=0;i<30;i++)
  {
    printf("%c", name[i]);
  }
  printf("\n B and I Variables Read from File, Predicting......\n");

  //Decision Tree
  //accelerator = 0 is a multicore, while 1 is a GPU
  
  //CPU Time
   struct timespec requestStart, requestEnd;
   clock_gettime(CLOCK_REALTIME, &requestStart);

  float deg = edges/vertices;
  if(deg < 0)
    deg = deg*-1;
  if(deg>1.0)
    deg = 1.0;

  if(vertex_division>=0.5)
  {
    if(pareto>=0.5 || pareto_division>=0.5)
    {
      accelerator = 1.0;
    }
    else
    {
      if(reduction>=0.5)
      {
        if(floating_point>=0.5)
        {
          if(vertices>=0.5 || edges>=0.5)
          {
            if(local_comp>=0.5)
            {
              accelerator = 0;
            }
            else
            {
              accelerator = 1;
            }
          }
          else
          {
            accelerator = 0;
          }
        }
        else
        {
          accelerator = 0;
        }
      }
      else
      {
        if(vertices>=0.5 || edges>=0.5)
        {
          accelerator = 0;
        }
        else
        {
          if(local_comp>=0.5)
          {  accelerator = 0;
            /*if(deg>=0.5)
            {
              if(diameter>=0.5)
              {
                accelerator = 0;
              }
              else  
              {
                accelerator = 1;
              }
            }
            else
            {
              accelerator = 0;
            }*/
          }
          else
          {
            accelerator = 1;
          }
        }
      }
    }
  }


  else
  {
    if(local_comp >=0.5)
    {
      accelerator = 0;
    }
    else
    {
      if(push_pop>=0.5)
      {
        if(deg>=0.5)
        {
          accelerator = 0;
        }
        else
        {
          accelerator = 1;
        }
      }
      else
      {
        if(reduction>=0.5)
        {
          if(floating_point>=0.5)
          {
            if(vertices>=0.5 || edges>=0.5)
            {
              if(local_comp>=0.5)
              {
                accelerator = 0;
              }
              else
              {
                accelerator = 1;
              }
            }
            else
            {
              accelerator = 0;
            }
          }
          else
          {
            accelerator = 0;
          }
        }
        else
        {
          if(vertices>=0.5 || edges>=0.5)
          {
            accelerator = 0;
          }
          else
          {
            accelerator = 1;
          }
        }
      }
    }
  }



  if(accelerator==0.0)
   printf("\n Accelerator Decided as: Reuse-Latency-Multicore\n");
  if(accelerator==1.0)
   printf("\n Accelerator Decided as: Throughput-Parallel-GPU\n");

  printf("\n Now Calculating Intra-Accelerator M Variables......");

  float avg_deg = 0;
  if(vertices == 0)
    avg_deg = max_edges - (edges);
  else
    avg_deg = max_edges - (edges/vertices);
  if(avg_deg<0)
    avg_deg = avg_deg*-1.0;
  if(avg_deg>=1)
    avg_deg = 1;
  avg_deg = avg_deg * 10.0;
  avg_deg = ceil(avg_deg);
  avg_deg = avg_deg/10.0;
  if(vertices==edges)
    if(max_edges==1.0)
      avg_deg = 1.0;
  printf("\n Avg_Deg: %f",avg_deg);
  
  float avg_deg_dia = (diameter + avg_deg)/2;
  printf("\n Avg_Deg_Dia: %f",avg_deg_dia);

  if(accelerator==0.0)
  {
    printf("\n Predicted Multicore Accelerator values \n");
    cores = (vertices*max_cores) + CORESMIN; //M2
    if(cores>max_cores)
      cores = max_cores;    
    int coresint = cores;
    printf("\n Cores: %d",coresint);

    multithreading = (avg_deg*max_multithreading) + MTMIN; //M3
    if(multithreading>max_multithreading)
      multithreading = max_multithreading;
    int multithreadingint = multithreading;
    printf("\n Multithreading: %d",multithreadingint);

    kmp_blocktime = ((contention + barriers)/2)*max_blocktime + BLOCKTIMEMIN; //M4
    if(kmp_blocktime>max_blocktime)
      kmp_blocktime = max_blocktime;
    int kmp_blocktimeint = kmp_blocktime;
    printf("\n KMP_BLOCKTIME: %d",kmp_blocktimeint);

    //KMP_PLACE_THREADS, 1=CORES, 2=THREADS, 3=OFFSET
    kmp_place_threads1 = cores; //M5
    kmp_place_threads2 = multithreading; //M6
    kmp_place_threads3 = (avg_deg_dia*max_thread_placement) + OFFSETMIN; //M7
    int offset = kmp_place_threads3;
    printf("\n KMP_PLACE_THREADS: %d %d %d",coresint,multithreadingint,offset);

    //For gcc, GOMP_CPU_AFFINITY may be used in lieu of KMP_AFFINITY
    //However, GOMP_CPU_AFFINITY requires manual placement.
    //granularity is always supposed to be fine 
    //Regardless, compact/scatter may be used manually there by converting the predicted values.
    char *to = affinity_type;
    kmp_affinity = ((avg_deg_dia + read_write_shared)/2) + KMP_AFFINITY_MIN; //M8
    if(kmp_affinity<0.3)
      to = stpcpy(to, "compact"); //Disallow data movement between cores
    else if(kmp_affinity>=0.3 && kmp_affinity<0.6)
      to = stpcpy(to, "balanced");
    else
      to = stpcpy(to, "scatter"); //Low R/W shared data, allow data movement between cores
    printf("\n THREAD AFFINITY: %s",affinity_type);

    //OMP nowait enable/disable depends on local computation for local barriers in omp loops
    omp_nowait = (floating_point + local_comp + barriers)/3;
    if(omp_nowait<0.5)
      omp_nowait = 0;
    else
      omp_nowait = 1;
    int omp_nowaitint = omp_nowait;
    printf("\n OMP_NOWAIT: %d, ENABLE:1, DISABLE:0",omp_nowaitint);
    
    //SIMD similar to multi-threading, depends on available density in inner edge loops
    pragma_simd = (avg_deg*max_simd) + SIMDMIN; //M10
    if(pragma_simd>max_simd)
      pragma_simd = max_simd;
    int pragma_simdint = pragma_simd;
    printf("\n SIMD: %d",pragma_simdint);


   //OMP scheduling, decides which scheduling to use for a benchmark-input combination
   int static1 = 0;
   int dynamic1 = 0;
   int guided1 = 0;
   int auto1 = 0;

   omp_schedule_static = (vertex_division + data_driven + read_only + contention)/4;
   omp_schedule_dynamic = (push_pop + reduction + indirect + read_write_shared)/4;
   omp_schedule_guided = (pareto + pareto_division + read_write_shared + diameter)/4;
   omp_schedule_auto = (vertex_division + reduction + data_driven + barriers)/4;
   
   if(omp_schedule_static >= omp_schedule_dynamic)
     if(omp_schedule_static >= omp_schedule_guided)
       if(omp_schedule_static >= omp_schedule_auto)
         static1 = 1;
   if(omp_schedule_dynamic > omp_schedule_static)
     if(omp_schedule_dynamic >= omp_schedule_guided)
       if(omp_schedule_dynamic >= omp_schedule_auto)
         dynamic1 = 1;
   if(omp_schedule_guided > omp_schedule_static)
     if(omp_schedule_guided > omp_schedule_dynamic)
       if(omp_schedule_guided >= omp_schedule_auto)
         guided1 = 1;
   if(omp_schedule_auto > omp_schedule_static)
     if(omp_schedule_auto > omp_schedule_dynamic)
       if(omp_schedule_auto > omp_schedule_guided)
         auto1 = 1;
   printf("\n OMP_SCHEDULE_STATIC: %f %d",omp_schedule_static, static1);
   printf("\n OMP_SCHEDULE_DYNAMIC: %f %d",omp_schedule_dynamic, dynamic1);
   printf("\n OMP_SCHEDULE_GUIDED: %f %d",omp_schedule_guided, guided1);
   printf("\n OMP_SCHEDULE_AUTO: %f %d",omp_schedule_auto, auto1);

   //chunk size if required
   omp_schedule_chunk_size = ((pareto + pareto_division + reduction + data_driven + read_only)/5)*MAX_CHUNK_SIZE + MIN_OMP_CHUNK_SIZE; 
   int omp_schedule_chunk_sizeint = omp_schedule_chunk_size;
   if(omp_schedule_chunk_sizeint > 2 && omp_schedule_chunk_sizeint < 4)
     omp_schedule_chunk_sizeint = 4;
   if(omp_schedule_chunk_sizeint > 4 && omp_schedule_chunk_sizeint < 8)
     omp_schedule_chunk_sizeint = 8;
   if(omp_schedule_chunk_sizeint > 8 && omp_schedule_chunk_sizeint < 16)
     omp_schedule_chunk_sizeint = 16;
   if(omp_schedule_chunk_sizeint > 16 && omp_schedule_chunk_sizeint < 32)
     omp_schedule_chunk_sizeint = 32;
   if(omp_schedule_chunk_sizeint > 32 && omp_schedule_chunk_sizeint < 64)
     omp_schedule_chunk_sizeint = 64;
   if(omp_schedule_chunk_sizeint > 64 && omp_schedule_chunk_sizeint < 128)
     omp_schedule_chunk_sizeint = 128;
   if(omp_schedule_chunk_sizeint > 128 && omp_schedule_chunk_sizeint < 256)
     omp_schedule_chunk_sizeint = 256;
   if(omp_schedule_chunk_sizeint > MAX_CHUNK_SIZE)
     omp_schedule_chunk_sizeint = MAX_CHUNK_SIZE;
   printf("\n OMP_SCHEDULE_CHUNK_SIZE: %d", omp_schedule_chunk_sizeint);
   
   //Only use Nested loops in more parallel benchmarks 
   omp_nested = (vertex_division + data_driven + read_only + barriers)/4;
   int omp_nestedint = 0;
   if(omp_nested >= 0.5)
     omp_nestedint = 1;
   else
     omp_nestedint = 0;
   printf("\n OMP_NESTED: %d",omp_nestedint);

   //If nesting is used in OpenMP, exploit inner parallelism
   omp_max_active_levels = (1.0-(push_pop + reduction + read_write_shared + contention)/4)*MAX_NESTING + MIN_NESTING;
   int omp_max_active_levelsint = omp_max_active_levels;
   if(omp_max_active_levelsint > MAX_NESTING)
     omp_max_active_levelsint = MAX_NESTING;
   printf("\n OMP_MAX_ACTIVE_LEVELS: %d", omp_max_active_levelsint);

   //Waiting for spins on atomics and context switches
   gomp_spincount = ((contention + barriers)/2)*MAX_SPINS + MIN_SPINS;
   int gomp_spincountint = gomp_spincount;
   if(gomp_spincountint > MAX_SPINS)
     gomp_spincountint = MAX_SPINS;
   printf("\n GOMP_SPINCOUNT: %d", gomp_spincountint);
  }

  //GPU INTRA CHOICES
  else
  {
    global_threads = (vertices*max_global_threads) + GPUMIN;
    if(global_threads > max_global_threads)
      global_threads = max_global_threads;

    local_threads = (avg_deg*max_local_threads) + GPUMIN;
    if(local_threads > max_local_threads)
      local_threads = max_local_threads;
    int local_threadsint = local_threads;
    int global_threadsint = global_threads;
    printf("\n GPU Local Threads: %d, \n GPU Global Threads: %d", local_threadsint, global_threadsint);
  }

  clock_gettime(CLOCK_REALTIME, &requestEnd);
  double accum = ( requestEnd.tv_sec - requestStart.tv_sec ) + ( requestEnd.tv_nsec - requestStart.tv_nsec ) / BILLION;
  printf( "\nTime Taken in Predictor:\n%lf seconds", accum );

 }//file rows 

  return 0;

}
