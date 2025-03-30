package ru.tusur.asu.model.deserializer;

import com.fasterxml.jackson.core.JacksonException;
import com.fasterxml.jackson.core.JsonParser;
import com.fasterxml.jackson.databind.DeserializationContext;
import com.fasterxml.jackson.databind.JsonDeserializer;
import com.fasterxml.jackson.databind.JsonNode;
import com.fasterxml.jackson.databind.node.IntNode;
import org.springframework.beans.factory.annotation.Autowired;
import ru.tusur.asu.model.Faculty;
import ru.tusur.asu.model.Organization;
import ru.tusur.asu.service.OrganizationService;

import java.io.IOException;

public class FacultyDeserializer extends JsonDeserializer<Faculty> {
    @Autowired
    private OrganizationService organizationService;

    @Override
    public Faculty deserialize(JsonParser jsonParser, DeserializationContext deserializationContext)
            throws IOException, JacksonException {
        JsonNode node = jsonParser.getCodec().readTree(jsonParser);
        Integer id = null;
        try {
            id = (Integer) ((IntNode) node.get("id")).numberValue();
        } catch (Exception ignored) {
        }

        Integer organization_id = (Integer) ((IntNode) node.get("organization_id")).numberValue();
        Organization organization = organizationService.read(organization_id);
        String name = node.get("name").asText();

        Faculty faculty = new Faculty();
        faculty.setId(id);
        faculty.setOrganization(organization);
        faculty.setName(name);

        return faculty;
    }
}
