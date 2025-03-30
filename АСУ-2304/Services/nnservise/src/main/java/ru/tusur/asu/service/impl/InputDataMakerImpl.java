package ru.tusur.asu.service.impl;

import org.nd4j.linalg.api.buffer.DataType;
import org.nd4j.linalg.api.ndarray.INDArray;
import org.nd4j.linalg.factory.Nd4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import ru.tusur.asu.model.Discipline;
import ru.tusur.asu.model.Indicator;
import ru.tusur.asu.model.Result;
import ru.tusur.asu.service.InputDataMaker;
import ru.tusur.asu.service.ResultService;

import java.util.LinkedHashSet;
import java.util.List;

@Service
public class InputDataMakerImpl implements InputDataMaker {

    @Autowired
    ResultService resultService;

    @Override
    public INDArray getStudentData(int id) {
        List<Result> results = resultService.readByStudent(id);

        LinkedHashSet<Integer>[] disciplinesSet = new LinkedHashSet[8];

        for (LinkedHashSet<Integer> set :disciplinesSet) {
            set = new LinkedHashSet<>();
        }

        float[][][] data = new float[8][8][9];

        for (Result result : results) {
            Indicator indicator = result.getIndicator();
            Discipline discipline = indicator.getDiscipline();

            int semester = discipline.getSemester();
            int disciplineId = discipline.getId();

            disciplinesSet[semester].add(disciplineId);
            int disciplineIndex = disciplinesSet[semester].
        }

        return Nd4j.create(DataType.FLOAT, 4, 4);
    }
}
