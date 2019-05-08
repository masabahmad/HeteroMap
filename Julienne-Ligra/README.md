Julienne-Ligra Examples
=======================

You can run ```make``` in the predictors directory to create executables for each program or use the following commands below

To run the HeteroMap decision_tree_model in this folder, do:
  ```../predictors/decision_tree_model rows Julienne-Ligra.csv```

rows exhibits how many benchmark-input combinations to predict in the .csv file. 27 for Julienne-Ligra.csv
The .csv file contains the benchmark and input model for a particular benchmark-input combination.

One can also use just one benchmark-input combination in file benchmark_input.csv using rows as 1 as an argument.

To add your own benchmark-input combination, simply decompose the target graph benchmark and input into its respective B and I variables using the methodology provided in the HeteroMap paper, and then write these variables into a .csv file. Then the .csv file can be run using the ```decision_tree_model``` executable. 

The examples in this folder are from Julienne-Ligra (https://github.com/jshun/ligra/blob/master/apps/bucketing/) in this regard, with input graphs as the same as the ones used in the HeteroMap paper.

Note for Julienne-Ligra, the HeteroMap predictor rightly selects the multicore accelerator for all Julienne-Ligra benchmark-input combinations. This is because its bucketing primitives set the Push-Pop parameter in the HeteroMap formulation, which have complex access patterns and branches, which do not perform well on GPUs.
Intra-accelerator choices for the multicore are then based on the input graph and the target benchmark's characteristics.

**Notes**
