HeteroMap Examples
==================

You can run ```make``` to create executables for each program or use the following commands below

To run decision_tree_model, do:
  ```./decision_tree_model rows multiple_benchmark_input.csv```

rows exhibits how many benchmark-input combinations to predict in the .csv file.

The .csv file contains the benchmark and input model for a particular benchmark-input combination.
You can add a benchmark to multiple_benchmark_input.csv with its input variables to predict the accelerator choices.

One can also use just one benchmark-input combination in file benchmark_input.csv using one row as an argument.

To add your own benchmark-input combination, simply decompose the target graph benchmark and input into its respective B and I variables using the methodology provided in the HeteroMap paper, and then write these variables into a .csv file. Then the .csv file can be run using the ```decision_tree_model``` executable. An example is provided with with the KCore implementation from Julienne-Ligra in this regard https://github.com/jshun/ligra/blob/master/apps/bucketing/KCore.C.

To recreate the predicted inter- and intra-accelerator choices in the paper, just use the variables from 
multiple_benchmark_input.csv to create the required benchmark-input combinations.

**Notes**
