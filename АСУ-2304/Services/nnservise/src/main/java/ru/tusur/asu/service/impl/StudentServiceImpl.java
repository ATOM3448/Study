package ru.tusur.asu.service.impl;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import ru.tusur.asu.model.Student;
import ru.tusur.asu.repository.StudentRepository;
import ru.tusur.asu.service.StudentService;

import java.util.List;

@Service
public class StudentServiceImpl implements StudentService {

    @Autowired
    private StudentRepository studentRepository;

    @Override
    public void create(Student student) {
        studentRepository.save(student);
    }

    @Override
    public List<Student> readAll() {
        return studentRepository.findAll();
    }

    @Override
    public Student read(Integer id) {
        return studentRepository.getReferenceById(id);
    }

    @Override
    public boolean update(Student student, Integer id) {
        if (!studentRepository.existsById(id)) {
            return false;
        }

        student.setId(id);
        studentRepository.save(student);

        return true;
    }

    @Override
    public boolean delete(Integer id) {
        if (!studentRepository.existsById(id)) {
            return false;
        }

        studentRepository.deleteById(id);

        return true;
    }
}
