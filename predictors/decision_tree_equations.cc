#include <cstdio>
#include <cstdlib>
#include <cmath>

//Multicore Specification Defines
#define CORESMIN 2
#define MTMIN 1
#define BLOCKTIMEMIN 1
#define PLACE1MIN 1
#define PLACE2MIN 1
#define PLACE3MIN 1

#define max_cores 61
#define max_multithreading 4
#define max_blocktime 1000
#define max_thread_placement1 1
#define max_thread_placement2 1
#define max_thread_placement3 1


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
  float deg = edges/vertices;
  if(deg>1.0)
    deg = 1.0;
  if(deg<0)
    deg = deg*-1;

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
          {
            if(deg>=0.5)
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
            }
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
    cores = (vertices*max_cores) + CORESMIN;
    multithreading = (avg_deg*max_multithreading) + MTMIN;
    kmp_blocktime = ((contention + barriers)/2)*max_blocktime + BLOCKTIMEMIN;
    kmp_place_threads1 = (avg_deg_dia*max_thread_placement1) + PLACE1MIN;
    kmp_place_threads2 = (avg_deg_dia*max_thread_placement2) + PLACE2MIN;
    kmp_place_threads3 = (avg_deg_dia*max_thread_placement3) + PLACE3MIN;
  }
  else
  {
    global_threads = (vertices*max_global_threads) + GPUMIN;
    if(global_threads > max_global_threads)
      global_threads = max_global_threads;
    local_threads = (avg_deg*max_local_threads) + GPUMIN;
    if(local_threads > max_local_threads)
      local_threads = max_local_threads;
    printf("\n GPU Local Threads: %f, \n GPU Global Threads: %f", local_threads, global_threads);
  }
 }//file rows 

  return 0;

}
