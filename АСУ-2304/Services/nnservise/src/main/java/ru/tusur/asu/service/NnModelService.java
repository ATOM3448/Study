package ru.tusur.asu.service;

import org.nd4j.linalg.api.ndarray.INDArray;

public interface NnModelService {
    boolean predict(INDArray input);
}
