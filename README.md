
HeteroMap v0.9 : A Runtime Performance Predictor for Efficient Processing of Graph Analytics on Heterogeneous Multi-Accelerators
====================================================================

[![build status](https://travis-ci.org/masabahmad/HeteroMap.svg?branch=master)](https://travis-ci.org/masabahmad/HeteroMap)

This is a pre-release repository containing HeteroMap's lightweight performance predictor, with performance and energy data acquired from various machine setups.
The proposed predictor utilizes an ontology of graph benchmarks and inputs to decide the optimal machine/accelerator and the selected machine's internal architectural choices.

If you use these benchmarks, please cite:

HeteroMap: A Runtime Performance Predictor for Efficient Processing of Graph Analytics on Heterogeneous Multi-Accelerators
ISPASS 2019.

Paper pdf is located at: 
https://khan.engr.uconn.edu/pubs/heteromap-ispass19.pdf

Requirements
============

1. Linux (Tested on Ubuntu 14.04)
2. g++ 4.6 (Tested with g++ 4.7)

Features
========

Getting Started
===============

Checkout the Repo:
```git clone https://github.com/masabahmad/HeteroMap```

To generate the executable for a predictor, run ```make``` inside the HeteroMap directory, then execute using the syntax specified by the individual README.md.

Contact
=======

masab.ahmad@uconn.edu
