package ru.tusur.asu.service.impl;

import org.deeplearning4j.nn.modelimport.keras.KerasModelImport;
import org.deeplearning4j.nn.modelimport.keras.exceptions.InvalidKerasConfigurationException;
import org.deeplearning4j.nn.modelimport.keras.exceptions.UnsupportedKerasConfigurationException;
import org.deeplearning4j.nn.multilayer.MultiLayerNetwork;
import org.nd4j.common.io.ClassPathResource;
import org.nd4j.linalg.api.ndarray.INDArray;
import org.springframework.stereotype.Service;
import ru.tusur.asu.service.NnModelService;

import java.io.IOException;

@Service
public class NnModelServiceImpl implements NnModelService {
    private MultiLayerNetwork model;
    {
        try {
            model = KerasModelImport.importKerasSequentialModelAndWeights(new ClassPathResource("model.h5").getFile().getPath(),
                    false);
        } catch (IOException | InvalidKerasConfigurationException e) {
            throw new RuntimeException(e);
        } catch (UnsupportedKerasConfigurationException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public boolean predict(INDArray input) {

        return false;
    }
}
