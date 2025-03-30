package ru.tusur.asu.model;

import jakarta.persistence.*;
import lombok.Getter;
import lombok.Setter;
import lombok.experimental.Accessors;
import org.hibernate.annotations.OnDelete;
import org.hibernate.annotations.OnDeleteAction;

@Getter
@Setter
@Accessors(chain=true)
@Entity
@Table(name = "PROFILE")
public class Profile {
    @Id
    @GeneratedValue(strategy = GenerationType.SEQUENCE)
    private Integer id;

    @ManyToOne(fetch = FetchType.LAZY)
    @JoinColumn(name = "program_id", foreignKey = @ForeignKey(name = "program_id"), nullable = false)
    @OnDelete(action = OnDeleteAction.CASCADE)
    private Program program;

    @Column(name = "name", nullable = false)
    private String name;
}
