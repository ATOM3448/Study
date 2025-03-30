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
@Table(name = "RESULT", uniqueConstraints = {@UniqueConstraint(columnNames = {"indicator_id", "student_id"})})
public class Result {
    @Id
    @GeneratedValue(strategy = GenerationType.SEQUENCE)
    private Integer id;

    @ManyToOne(fetch = FetchType.LAZY)
    @JoinColumn(name = "indicator_id", foreignKey = @ForeignKey(name = "indicator_id"), nullable = false)
    @OnDelete(action = OnDeleteAction.CASCADE)
    private Indicator indicator;

    @ManyToOne(fetch = FetchType.LAZY)
    @JoinColumn(name = "student_id", foreignKey = @ForeignKey(name = "student_id"), nullable = false)
    @OnDelete(action = OnDeleteAction.CASCADE)
    private Student student;

    @Column(name = "value", nullable = false)
    private Double value;

    @Column(name = "is_prediction", nullable = false)
    private Boolean isPrediction;
}
