package ru.tusur.asu.service;

import org.nd4j.linalg.api.ndarray.INDArray;

public interface InputDataMaker {
    INDArray getStudentData(int id);
}
