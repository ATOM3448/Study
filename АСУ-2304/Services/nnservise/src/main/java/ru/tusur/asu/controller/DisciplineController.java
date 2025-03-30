package ru.tusur.asu.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import ru.tusur.asu.model.Discipline;
import ru.tusur.asu.service.DisciplineService;

import java.util.List;

@RestController
public class DisciplineController {
    private static final String mapping = "/api/disciplines";

    private final DisciplineService disciplineService;

    @Autowired
    public DisciplineController(DisciplineService disciplineService) {
        this.disciplineService = disciplineService;
    }

    @GetMapping(value = mapping + "/{id}")
    public ResponseEntity<Discipline> read(@PathVariable(name = "id") int id) {
        final Discipline discipline = disciplineService.read(id);

        return discipline != null
                ? new ResponseEntity<>(discipline, HttpStatus.OK)
                : new ResponseEntity<>(HttpStatus.NOT_FOUND);
    }

    @GetMapping(value = mapping)
    public ResponseEntity<List<Discipline>> readAll() {
        final List<Discipline> disciplines = disciplineService.readAll();

        return disciplines != null && !disciplines.isEmpty()
                ? new ResponseEntity<>(disciplines, HttpStatus.OK)
                : new ResponseEntity<>(HttpStatus.NOT_FOUND);
    }

    @PostMapping(value = mapping)
    public ResponseEntity<?> create(@RequestBody Discipline discipline) {
        disciplineService.create(discipline);
        return new ResponseEntity<>(HttpStatus.CREATED);
    }

    @PutMapping(value = mapping + "/{id}")
    public ResponseEntity<?> update(@PathVariable(name = "id") int id,
                                    @RequestBody Discipline discipline) {
        final boolean updated = disciplineService.update(discipline, id);

        return updated
                ? new ResponseEntity<>(HttpStatus.OK)
                : new ResponseEntity<>(HttpStatus.NOT_MODIFIED);
    }

    @DeleteMapping(value = mapping + "/{id}")
    public ResponseEntity<?> delete(@PathVariable(name = "id") int id) {
        final boolean deleted = disciplineService.delete(id);

        return deleted
                ? new ResponseEntity<>(HttpStatus.OK)
                : new ResponseEntity<>(HttpStatus.NOT_MODIFIED);
    }
}
