package ru.tusur.asu.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import ru.tusur.asu.model.IndicatorGroup;
import ru.tusur.asu.service.IndicatorGroupService;

import java.util.List;

@RestController
public class IndicatorGroupController {
    private static final String mapping = "/api/indicatorGroups";

    private final IndicatorGroupService indicatorGroupService;

    @Autowired
    public IndicatorGroupController(IndicatorGroupService indicatorGroupService) {
        this.indicatorGroupService = indicatorGroupService;
    }

    @GetMapping(value = mapping + "/{id}")
    public ResponseEntity<IndicatorGroup> read(@PathVariable(name = "id") int id) {
        final IndicatorGroup indicatorGroup = indicatorGroupService.read(id);

        return indicatorGroup != null
                ? new ResponseEntity<>(indicatorGroup, HttpStatus.OK)
                : new ResponseEntity<>(HttpStatus.NOT_FOUND);
    }

    @GetMapping(value = mapping)
    public ResponseEntity<List<IndicatorGroup>> readAll() {
        final List<IndicatorGroup> indicatorGroups = indicatorGroupService.readAll();

        return indicatorGroups != null && !indicatorGroups.isEmpty()
                ? new ResponseEntity<>(indicatorGroups, HttpStatus.OK)
                : new ResponseEntity<>(HttpStatus.NOT_FOUND);
    }

    @PostMapping(value = mapping)
    public ResponseEntity<?> create(@RequestBody IndicatorGroup indicatorGroup) {
        indicatorGroupService.create(indicatorGroup);
        return new ResponseEntity<>(HttpStatus.CREATED);
    }

    @PutMapping(value = mapping + "/{id}")
    public ResponseEntity<?> update(@PathVariable(name = "id") int id,
                                    @RequestBody IndicatorGroup indicatorGroup) {
        final boolean updated = indicatorGroupService.update(indicatorGroup, id);

        return updated
                ? new ResponseEntity<>(HttpStatus.OK)
                : new ResponseEntity<>(HttpStatus.NOT_MODIFIED);
    }

    @DeleteMapping(value = mapping + "/{id}")
    public ResponseEntity<?> delete(@PathVariable(name = "id") int id) {
        final boolean deleted = indicatorGroupService.delete(id);

        return deleted
                ? new ResponseEntity<>(HttpStatus.OK)
                : new ResponseEntity<>(HttpStatus.NOT_MODIFIED);
    }
}
