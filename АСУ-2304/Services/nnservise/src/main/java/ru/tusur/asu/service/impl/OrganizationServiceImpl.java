package ru.tusur.asu.service.impl;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import ru.tusur.asu.model.Organization;
import ru.tusur.asu.repository.OrganizationRepository;
import ru.tusur.asu.service.OrganizationService;

import java.util.List;

@Service
public class OrganizationServiceImpl implements OrganizationService {

    @Autowired
    private OrganizationRepository organizationRepository;

    @Override
    public void create(Organization organization) {
        organizationRepository.save(organization);
    }

    @Override
    public List<Organization> readAll() {
        return organizationRepository.findAll();
    }

    @Override
    public Organization read(Integer id) {
        return organizationRepository.getReferenceById(id);
    }

    @Override
    public boolean update(Organization organization, Integer id) {
        if (!organizationRepository.existsById(id)) {
            return false;
        }

        organization.setId(id);
        organizationRepository.save(organization);

        return true;
    }

    @Override
    public boolean delete(Integer id) {
        if (!organizationRepository.existsById(id)) {
            return false;
        }

        organizationRepository.deleteById(id);

        return true;
    }
}
